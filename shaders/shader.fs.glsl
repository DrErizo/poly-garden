#version 330 core
precision mediump float;
out vec4 FragColor;
in vec2 vPos;
in vec3 vColor;

vec2 center = vec2(0,0);
void main(){
    FragColor = vec4(vColor, 1.0f);
	/* vec2 center = vec2(vPos.x - 0.5, vPos.y - 0.5); 
	float dist = distance(center, vec2(gl_FragCoord.x / 1920, gl_FragCoord.y / 1080));
	if(dist > 0.5){
		//discard;
		FragColor = vec4(0,0,0, 1.0);
	}else{
		FragColor = vec4(vColor,1.0);
	} */
}
