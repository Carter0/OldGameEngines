/* from https://www.lighthouse3d.com/tutorials/glsl-12-tutorial/directional-light-per-pixel/ */

varying vec4 diffuse,ambient;
varying vec3 normal,halfVector;
varying float objY; // Keep track of the y component.
 
void main()
{
    vec3 n,halfV,lightDir;
    float NdotL,NdotHV;
 
    lightDir = vec3(gl_LightSource[0].position);
 
    /* The ambient term will always be present */
    vec4 color = ambient;
    
    /* a fragment shader can't write a varying variable, hence we need a new variable to store the normalized interpolated normal */
    n = normalize(normal);
    
    /* compute the dot product between normal and ldir */
    NdotL = max(dot(n,lightDir),0.0);

    float scale = 0.5 + 0.5 * max(0.0, 1.0 + sin(objY));



    if (NdotL > 0.0) {
        color += diffuse * NdotL * scale;
        halfV = normalize(halfVector);
        NdotHV = max(dot(n,halfV),0.0);
        color += gl_FrontMaterial.specular *
                gl_LightSource[0].specular *
                pow(NdotHV, gl_FrontMaterial.shininess);
    }

    //color = vec4(scale, scale, scale, 1.0);
    gl_FragColor = color;
}
