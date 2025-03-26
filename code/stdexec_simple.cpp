const auto fn1 = [...](auto i) noexcept {/*...*/};
const auto fn2 = [...](auto i) noexcept {/*...*/};

const auto work = stdexec::when_all(
    stdexec::just() | exec::on(gpu.get_scheduler(), 
                        stdexec::bulk(N, insert_s_human)),
    stdexec::just() | exec::on(cpu.get_scheduler(), 
                        stdexec::bulk(N, insert_s_mosquito)))
stdexec::sync_wait(work);
