# `_vm_object_copy` output-pointer 반환 경계

Open item 2의 COW object-copy 결과 전달을 원본 명령으로 확인했다. Callee의 입력 ESI가
zero이면 two caller-owned locations에 zero를 쓰고 common RET로 간다. Fast path는 output
pointer location에 ESI, offset location에 input offset, flag location에 1을 쓴다. 공통
tail은 flag location에 0을 쓴 뒤 RET한다.

유일한 RET epilogue 직전에는 EAX write가 없다. 따라서 raw 결과 계약은 EAX error status가
아니라 caller-provided pointer/offset/flag locations이다. C type, allocation-failure path,
indirect caller와 모든 runtime lifetime은 이 결과로 확정하지 않는다.
