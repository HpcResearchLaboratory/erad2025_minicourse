template <typename T, size_t N>
auto vector_add(const std::array<T, N>& A, const std::array<T, N>& B,
                std::array<T, N>& C) -> void {
#pragma acc parallel loop copyin(A, B) copyout(C)
  for (auto i = 0ull; i < N; ++i) C[i] = A[i] + B[i];
}
