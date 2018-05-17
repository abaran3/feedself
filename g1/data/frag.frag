#version 150

uniform sampler2DRect tex0;
in vec2 texCoordVarying;
out vec4 outputColor;
uniform float itt;
uniform float blurAmnt;

void main()
{
	float windowWidth = 1024.0;
	float windowHeight = 768.0;
	vec2 uv= texCoordVarying;

	float amount = 0.0;
	
	amount = (1.0 + sin(blurAmnt*6.0)) * 0.5;
	amount *= 1.0 + sin(blurAmnt*16.0) * 0.5;
	amount *= 1.0 + sin(blurAmnt*19.0) * 0.5;
	amount *= 1.0 + sin(blurAmnt*27.0) * 0.5;
	amount = pow(amount, 3.0);

	amount *= 0.005;
	// amount *= blurAmnt;
	amount = windowWidth*amount;
    vec3 col;
    col.r = texture( tex0, vec2(uv.x+amount,uv.y) ).r;
    col.g = texture( tex0, uv ).g;
    col.b = texture( tex0, vec2(uv.x-amount,uv.y) ).b;

		// col *= (1.0 - amount * 0.5);
		// col = texture(tex0, uv).rgb;
    outputColor = vec4(col,1.0);
}

// #version 150

// out vec4 outputColor;

// void main()
// {
//     // gl_FragCoord contains the window relative coordinate for the fragment.
//     // we use gl_FragCoord.x position to control the red color value.
//     // we use gl_FragCoord.y position to control the green color value.
//     // please note that all r, g, b, a values are between 0 and 1.

//     float windowWidth = 1024.0;
//     float windowHeight = 768.0;

//     float r = gl_FragCoord.x / windowWidth;
//     float g = gl_FragCoord.y / windowHeight;
//     float b = 1.0;
//     float a = 1.0;
//     outputColor = vec4(r, g, b, a);
// }

// #version 150

// uniform sampler2DRect tex0;

// in vec2 texCoordVarying;
// out vec4 outputColor;

// void main()
// {
//     vec4 color;

//     color += 1.0 * texture(tex0, texCoordVarying + vec2(blurAmnt * -4.0, 0.0));
//     color += 2.0 * texture(tex0, texCoordVarying + vec2(blurAmnt * -3.0, 0.0));
//     color += 3.0 * texture(tex0, texCoordVarying + vec2(blurAmnt * -2.0, 0.0));
//     color += 4.0 * texture(tex0, texCoordVarying + vec2(blurAmnt * -1.0, 0.0));

//     color += 5.0 * texture(tex0, texCoordVarying + vec2(blurAmnt, 0));

//     color += 4.0 * texture(tex0, texCoordVarying + vec2(blurAmnt * 1.0, 0.0));
//     color += 3.0 * texture(tex0, texCoordVarying + vec2(blurAmnt * 2.0, 0.0));
//     color += 2.0 * texture(tex0, texCoordVarying + vec2(blurAmnt * 3.0, 0.0));
//     color += 1.0 * texture(tex0, texCoordVarying + vec2(blurAmnt * 4.0, 0.0));

//     color /= 25.0;

//     outputColor = color;
// }