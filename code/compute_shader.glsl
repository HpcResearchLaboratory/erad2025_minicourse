#version 460

layout(local_size_x = 16, local_size_y = 16) in;
layout(binding = 0, rgba8) uniform readonly image2D inputImage;
layout(binding = 1, rgba8) uniform writeonly image2D outputImage;

void main() {
    ivec2 pixelCoords = ivec2(gl_GlobalInvocationID.xy);
    vec4 pixelColor = imageLoad(inputImage, pixelCoords);
    vec4 invertedColor = vec4(vec3(1.0) - pixelColor.rgb, pixelColor.a);
    imageStore(outputImage, pixelCoords, invertedColor);
}
