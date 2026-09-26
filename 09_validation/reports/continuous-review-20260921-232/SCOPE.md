# 범위

원본 x86 `mach_kernel`과 원본-derived memory-block/function export만 사용했다. Python은 4-byte
pattern의 전체 파일 검색, file offset→initialized image VA, hit 수, 주변 8-byte record를 계산했다.

범위는 `_unmount` entry 값의 static byte alias와 `_unix_syscall`의 shown table-reader 명령이다.
첫 word 의미, dispatch invocation, source-level ABI 및 runtime behavior는 범위 밖이다.
