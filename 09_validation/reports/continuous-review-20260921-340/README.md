# 340차 정적 검토 — _panic의 noreturn export 서명과 RET 바이트 대조

0x0010ca6c의 _panic은 full-pass5 JSON에서 noreturn 서명을 가지지만, 원본 OPENSTEP x86 mach_kernel의 3개 body segment와 54개 내보내기 명령을 직접 CFG로 대조하면 모든 명령이 진입점에서 도달 가능하고 0x0010cb23의 C3 RET도 도달 가능하다.

이 결과는 _panic이 실제 실행 중 반환한다는 주장이 아니다. 직접 분기와 fall-through만을 따른 정적 모델에서, noreturn 서명만으로 호출 뒤 코드의 도달성이나 반환 동작을 확정할 수 없다는 근거다.
