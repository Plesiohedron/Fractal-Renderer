#version 460 core

uniform dvec2 scale;
uniform dvec2 window_size;
uniform dvec2 offset;
uniform dvec2 mouse_pos;  // unused
uniform float angle;  // unused
uniform sampler2D texture0;

out vec4 color;

const int MAX_ITERATIONS = 255;
const int SQUARE_MAX_LENGTH = 2 * 2;
const dvec2 CENTER_OFFSET = dvec2(0.5, 0.5);

dvec2 function(dvec2 z, dvec2 c) {
	return dvec2(z.x * z.x - z.y * z.y + c.x, 2 * z.x * z.y + c.y);
}

void main() {
	dvec2 Z = (gl_FragCoord.xy / window_size - CENTER_OFFSET) / scale + offset / window_size;
	const dvec2 C = Z;
	vec4 fractal_color = vec4(0.0f, 0.0f, 0.0f, 1.0f);

	for (int iteration = 0; iteration < MAX_ITERATIONS; ++iteration) {
		Z = function(Z, C);

		if (dot(Z, Z) > SQUARE_MAX_LENGTH) {
			float abs_Z = float(dot(Z, Z));
			float index = max(float(iteration + 1) - log(log(abs_Z)) / log(2), 0.0f);
			fractal_color = texture(texture0, vec2(index / MAX_ITERATIONS, 0.5f));
			break;
		}
	}

	color = fractal_color;
}