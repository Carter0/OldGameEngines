// Support Code written by Michael D. Shah
// Updated by Seth Cooper
// OpenGL code based on https://www.turbonut.com/2019/03/18/opengl3-sdl2/; https://www.khronos.org/opengl/wiki; and https://www.lighthouse3d.com/tutorials/glsl-12-tutorial
// Last Updated: Spring 2020
// Please do not redistribute without asking permission.

#include "SDLGraphicsProgram.hpp"
#include <math.h>



template< typename F1, typename F2 >
static void checkResult(const std::string & what, GLuint id, GLuint status, F1 getFunc, F2 logFunc)
{
  GLint isOk = GL_FALSE;
  getFunc(id, status, &isOk);
  if(isOk == GL_FALSE) {
    GLint maxLength = 0;
    getFunc(id, GL_INFO_LOG_LENGTH, &maxLength);

    std::vector<GLchar> errorLog(maxLength);
    logFunc(id, maxLength, &maxLength, &errorLog[0]);
    
    std::cout << "Error in " << what << ": " << &errorLog[0] << std::endl;
  }
}

static bool loadString(const std::string & filename, std::string & contents)
{
  std::ifstream file(filename);
  if (!file) {
    std::cout << "Error opening " << filename << std::endl;
    return false;
  }
  
  std::stringstream buffer;
  buffer << file.rdbuf();
  contents = buffer.str();

  return true;
}

static void estimateNormals(std::vector< GLfloat > & verticesAndNormals, const std::vector< GLuint > & indices)
{
  for (size_t ii = 0; ii < indices.size() / 3; ii ++) {
    //   for each triangle (defined by three vertices),
    //   compute the triangle normal.
    //   then, add that normal to the vertex normal for each
    //   of the triangle's vertices.
    //
    //   the vertex information is arranged in verticesAndNormals like this (where v is a vertex and n is a normal):
    //     [ vx0 vy0 vz0 nx0 ny0 nz0 vx1 vy1 vz1 nx1 ny1 nz1 ...]
    //   the triangles themseves are defined in indices like this (where each triangle has vertices a, b, and c):
    //     [ a0 b0 c0 a1 b1 c1 ... ]

    // These get the verticies for a particular triangle. Loop divides by 3.
    GLuint v0 = indices[ii * 3 + 0];
    GLuint v1 = indices[ii * 3 + 1];
    GLuint v2 = indices[ii * 3 + 2];

    // Each vertex has 6 fields in it for the x,y,x and normals and stuff. 
    GLuint t0x = verticesAndNormals[6 * v0 + 0];
    GLuint t0y = verticesAndNormals[6 * v0 + 1];
    GLuint t0z = verticesAndNormals[6 * v0 + 2];
    GLuint t1x = verticesAndNormals[6 * v1 + 0];
    GLuint t1y = verticesAndNormals[6 * v1 + 1];
    GLuint t1z = verticesAndNormals[6 * v1 + 2];
    GLuint t2x = verticesAndNormals[6 * v2 + 0];
    GLuint t2y = verticesAndNormals[6 * v2 + 1];
    GLuint t2z = verticesAndNormals[6 * v2 + 2];

    // Get ready to do the cross product.
    GLfloat dx1 = t1x - t0x;
    GLfloat dy1 = t1y - t0y;
    GLfloat dz1 = t1z - t0z;
    GLfloat dx2 = t2x - t0x;
    GLfloat dy2 = t2y - t0y;
    GLfloat dz2 = t2z - t0z;

    // Doing the cross product.
    GLfloat cx = dy1 * dz2 - dz1 * dy2;
    GLfloat cy = dz1 * dx2 - dx1 * dz2;
    GLfloat cz = dx1 * dy2 - dy1 * dx2;

    verticesAndNormals[v0 * 6 + 3] += cx;
    verticesAndNormals[v0 * 6 + 4] += cy;
    verticesAndNormals[v0 * 6 + 5] += cz;
    verticesAndNormals[v1 * 6 + 3] += cx;
    verticesAndNormals[v1 * 6 + 4] += cy;
    verticesAndNormals[v1 * 6 + 5] += cz;
    verticesAndNormals[v2 * 6 + 3] += cx;
    verticesAndNormals[v2 * 6 + 4] += cy;
    verticesAndNormals[v2 * 6 + 5] += cz;

   
  }

  for (size_t ii = 0; ii < verticesAndNormals.size() / 6; ii ++) {
    float x = verticesAndNormals[6 * ii + 3];
    float y = verticesAndNormals[6 * ii + 4];
    float z = verticesAndNormals[6 * ii + 5];

    float len = sqrtf(x * x + y * y + z * z);

    verticesAndNormals[6 * ii + 3] /= len;
    verticesAndNormals[6 * ii + 4] /= len;
    verticesAndNormals[6 * ii + 5] /= len;

  }
}


static bool loadMesh(const std::string & filename, std::vector< GLfloat > & verticesAndNormals, std::vector< GLuint > & indices)
{
  verticesAndNormals.clear();
  indices.clear();

  std::ifstream file(filename);
  if (!file) {
    std::cout << "Error opening " << filename << std::endl;
    return false;
  }

  std::string line;
  while (std::getline(file, line)) {
    if (line.length() == 0 || line[0] == '#') {
      continue;
    }

    std::stringstream linestr(line);

    std::string type;
    linestr >> type;

    if (type == "v") {
      GLfloat x, y, z;
      linestr >> x >> y >> z;
      if (!linestr) {
	std::cout << "Error reading " << filename << " in line: " << line << std::endl;
	return false;
      }
      verticesAndNormals.push_back(x);
      verticesAndNormals.push_back(y);
      verticesAndNormals.push_back(z);
      verticesAndNormals.push_back(0.0f);
      verticesAndNormals.push_back(0.0f);
      verticesAndNormals.push_back(0.0f);
    } else if (type == "f") {
      GLuint a, b, c;
      linestr >> a >> b >> c;
      if (!linestr) {
	std::cout << "Error reading " << filename << " in line: " << line << std::endl;
	return false;
      }
      if (a < 1 || a > verticesAndNormals.size() || b < 1 || b > verticesAndNormals.size() || c < 1 || c > verticesAndNormals.size()) {
	std::cout << "Error reading " << filename << "; bad index in line: " << line << std::endl;
      }
      indices.push_back(a - 1);
      indices.push_back(b - 1);
      indices.push_back(c - 1);
    } else {
      std::cout << "Error reading " << filename << " in line: " << std::endl;
    }
  }

  estimateNormals(verticesAndNormals, indices);

  return true;
}



// Initialization function
// Returns a true or false value based on successful completion of setup.
// Takes in dimensions of window.
SDLGraphicsProgram::SDLGraphicsProgram(int w, int h):screenHeight(h),screenWidth(w){
  // Initialize random number generation.
  srand(time(NULL));



  // Initialization flag
  bool success = true;
  // String to hold any errors that occur.
  std::stringstream errorStream;
  // The window we'll be rendering to
  gWindow = NULL;

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  
  // Initialize SDL
  if(SDL_Init(SDL_INIT_EVERYTHING)< 0){
    errorStream << "SDL could not initialize! SDL Error: " << SDL_GetError() << "\n";
    success = false;
  }
  else{
    //Create window
    gWindow = SDL_CreateWindow( "Lab", 100, 100, screenWidth, screenHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    // Check if Window did not create.
    if( gWindow == NULL ){
      errorStream << "Window could not be created! SDL Error: " << SDL_GetError() << "\n";
      success = false;
    } else {
      gGLContext = SDL_GL_CreateContext(gWindow);
      // Check if context did not create.
      if( gGLContext == NULL ){
	errorStream << "Context could not be created! SDL Error: " << SDL_GetError() << "\n";
	success = false;
      } else {
	// Initialize GLAD Library                                                                                                                                                                  
	gladLoadGLLoader(SDL_GL_GetProcAddress);
	printf("Vendor: %s\n", glGetString(GL_VENDOR));
	printf("Renderer: %s\n", glGetString(GL_RENDERER));
	printf("Version: %s\n", glGetString(GL_VERSION));
	printf("Shading language: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));

	// read shaders
	

	
	

	// load in model
	std::string vertexShaderStr;
	std::string fragmentShaderStr;
	std::vector< GLfloat > verticesAndNormals;
	std::vector< GLuint > indices;
	if (!loadString("res/vertex.glsl", vertexShaderStr) || !loadString("res/fragment.glsl", fragmentShaderStr) || !loadMesh("res/teddy.obj", verticesAndNormals, indices)) {
	  errorStream << "Error loading model!\n";
	  success = false;
	} else {
	  // set up shaders
	  const char * vertexShader = vertexShaderStr.c_str();
	  GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	  glShaderSource(vertexShaderID, 1, &vertexShader, nullptr);
	  glCompileShader(vertexShaderID);
	  checkResult("vertexShader", vertexShaderID, GL_COMPILE_STATUS, glGetShaderiv, glGetShaderInfoLog);
	  
	  const char * fragmentShader = fragmentShaderStr.c_str();
	  GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	  glShaderSource(fragmentShaderID, 1, &fragmentShader, nullptr);
	  glCompileShader(fragmentShaderID);
	  checkResult("fragmentShader", fragmentShaderID, GL_COMPILE_STATUS, glGetShaderiv, glGetShaderInfoLog);

	  gShaderProgramID = glCreateProgram();
	  glAttachShader(gShaderProgramID, vertexShaderID);
	  glAttachShader(gShaderProgramID, fragmentShaderID);
	  glLinkProgram(gShaderProgramID);
	  checkResult("shaderProgram", gShaderProgramID, GL_LINK_STATUS, glGetProgramiv, glGetProgramInfoLog);
	
	  glDetachShader(gShaderProgramID, vertexShaderID);
	  glDetachShader(gShaderProgramID, fragmentShaderID);
	  glDeleteShader(vertexShaderID);
	  glDeleteShader(fragmentShaderID);
	  glUseProgram(gShaderProgramID);
	  
	  // set up vertex buffer
	  glGenBuffers(1, &gVertexBufferID);
	  glBindBuffer(GL_ARRAY_BUFFER, gVertexBufferID);
	  glBufferData(GL_ARRAY_BUFFER, verticesAndNormals.size() * sizeof(GLfloat), &verticesAndNormals[0], GL_STATIC_DRAW);

	  glEnableClientState(GL_VERTEX_ARRAY);
	  glVertexPointer(3, GL_FLOAT, 6 * sizeof(GLfloat), (void *)0);
	  glEnableClientState(GL_NORMAL_ARRAY);
	  glNormalPointer(GL_FLOAT, 6 * sizeof(GLfloat), (void *)(3 * sizeof(GLfloat)));
	  
	  // set up index buffer
	  glGenBuffers(1, &gIndexBufferID);
	  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, gIndexBufferID);
	  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), &indices[0], GL_STATIC_DRAW);
	  gElementCount = indices.size();

	  // general setup
	  glEnable(GL_DEPTH_TEST);

	  GLfloat lightPos[] = {0.0f, 0.1f, -1.0f, 1.0f};
	  glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	  GLfloat lightAmb[] = {0.5f, 0.5f, 0.5f, 1.0f};
	  glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	  GLfloat lightDif[] = {0.5f, 0.5f, 0.5f, 1.0f};
	  glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif);
	}
      }
    }
  }

  // If initialization did not work, then print out a list of errors in the constructor.
  if(!success){
    errorStream << "Failed to initialize!\n";
    std::string errors=errorStream.str();
    std::cout << errors << "\n";
  }else{
    std::cout << "No SDL errors Detected in during init\n\n";
  }
}




// Proper shutdown and destroy initialized objects
SDLGraphicsProgram::~SDLGraphicsProgram(){
  // Destroy context
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glDeleteBuffers(1, &gVertexBufferID);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  glDeleteBuffers(1, &gIndexBufferID);
  glUseProgram(0);
  glDeleteProgram(gShaderProgramID);
  SDL_GL_DeleteContext(gGLContext);
  gGLContext = nullptr;
  //Destroy window
  SDL_DestroyWindow( gWindow );
  gWindow = nullptr;
  //Quit SDL subsystems
  SDL_Quit();
}



// Update OpenGL
void SDLGraphicsProgram::update()
{
}


// Render
// The render function gets called once per loop
void SDLGraphicsProgram::render(){
  
  // Stuff happens from the bottom function to the top, like a stack.
  glClearColor(0,0,1,1);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glPushMatrix();

  // Rotates the model by the ticks divided by some amount.
  glRotatef(SDL_GetTicks() / 50.0f, 0.0f, 1.0f, 0.0f);
  glScalef(0.02f, 0.02f, 0.02f);
  glDrawElements(GL_TRIANGLES, gElementCount, GL_UNSIGNED_INT, (void *)0);
  glPopMatrix();
  SDL_GL_SwapWindow(gWindow);
}



//Loops forever!
void SDLGraphicsProgram::loop(){
  // Main loop flag
  // If this is quit = 'true' then the program terminates.
  bool quit = false;
  // Event handler that handles various events in SDL
  // that are related to input and output
  SDL_Event e;
  // Enable text input
  SDL_StartTextInput();

    
  // While application is running
  while(!quit){
    //Handle events on queue
    while(SDL_PollEvent( &e ) != 0){
      // User posts an event to quit
      // An example is hitting the "x" in the corner of the window.
      if(e.type == SDL_QUIT){
	quit = true;
      }		
    }

    // Update our scene
    update();
    // Render using OpenGL
    render();
    //Update screen of our specified window
    
    // If you have time, implement your frame capping code here
    // Otherwise, this is a cheap hack for this lab.
    SDL_Delay(50);
  }

  //Disable text input
  SDL_StopTextInput();
}
