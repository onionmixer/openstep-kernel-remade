# 범위와 방법

이 검토는 OPENSTEP x86 원본 `mach_kernel` 바이트와 그 바이너리에서 만든 full-pass5
export만 사용했다. `01_resources` 및 재구성 코드, 다른 커널 소스와 실행·에뮬레이션은
사용하지 않았다.

주소, 함수별 body byte 수, decoded instruction 수, direct call 수와 반환 지점 수는 모두
Python으로 계산했다. Ghidra C는 candidate control-flow를 찾는 보조 자료였고, 최종
사실은 `__text`에서 읽은 명령으로만 기록했다.

`vm_fault`와 caller의 반환 처리, `vm_object_copy`, `vm_object_shadow`,
`vm_object_coalesce`, `vm_fault_copy_entry`, `vm_map_copy_entry`, `vm_map_fork`,
`vm_map_deallocate`를 대상 함수로 한정했다.
