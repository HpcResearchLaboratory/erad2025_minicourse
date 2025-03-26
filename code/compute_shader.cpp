GLuint createComputeShader() {/*...*/ }

auto main() -> int {
    /*...*/
    GLuint computeShaderProgram = createComputeShader();
    /*...*/
    glUseProgram(computeShaderProgram);
    glDispatchCompute(16, 16, 1);
    glMemoryBarrier(GL_SHADER_IMAGE_ACCESS_BARRIER_BIT);
    /*...*/
}
