# 범위

원본 x86 `mach_kernel`과 원본-derived full-pass5 export만 사용했다. Python은 선택 명령의
VA→file offset, 전체 `__text` E8 rel32 target, caller 수·본문 byte 합계를 계산하고 원본
bytes와 대조했다.

이 검토는 선택 VFS list와 lock 호출의 국소 정적 흐름만 다룬다. VFS object/type 의미,
panic helper의 no-return, all caller/indirect caller, list validity·ownership·lifetime,
동시성·hardware·runtime execution은 범위 밖이다.
