# 코딩 전 검토와 RF 불일치 재검토

vm_contract_review27에게 native IDT 진단 설계를 코딩 전에 읽기 전용으로 검토받았다.
root는 원본 ASM과 보고서24의 IDT 계약을 직접 확인했다.

반영 사항:

- CS-relative gate offset/EIP와 linear IDTR/GDTR를 구별한다.
- high SS frame은 SS.base+ESP의 paging 결과로 확인한다.
- CPL0 NP write의 error U/S는 FS selector나 PTE user bit로 추측하지 않는다.
- trap gate IF 보존을 IF=1에서도 시험하고 DF 보존 관측 후 CLD한다.
- RF 저장 frame과 PUSHFD 관측을 구별한다.
- 높은 DS 기본 INVLPG 대신 FS override로 정확한 낮은 user 주소를 무효화한다.
- 서로 다른 payload와 sentinel로 각 retry를 확인하고 모든 비-PF gate는 fatal로 보낸다.

첫 실행은 반복 PF와 retry 후 정상 진단 종료를 했지만 RF assertion에서 실패했다.
assertion을 제거하거나 CPU frame을 수정하지 않았다. 별도 진단 수집 모드는 실패를
명시해 독립 IF/DF 조건을 수집하며, 기본 strict 명령은 계속 실패한다.

root와 검토자가 각각 Python/원시 명령으로 확인한 frame 경계:

- PF 직전 ESP17fffc → CPU frame17ffec → PUSHAD 후17ffcc.
- PUSHFD scratch17ffc8은 CPU frame보다 아래이며 저장 flags17fff8을 덮지 않는다.
- 10101f의 frame 주소와 10102c REP MOVSD는 원래4DWORD를 복사한다.
- CLD는 현재 DF만 변경하며 원시 frame에 쓰지 않는다.

검토자는 case2 raw output의 두 saved flags=2, e4/f5 sentinel window,
PTE200067과 반환 SP180000도 독립 확인했다. root는 모든 IF/DF 조건을 수집·감사했다.
따라서 현재 증거는 frame 복사 오류보다 CPU 모델 RF 불일치를 지지하지만,
해당 설치 버전 내부 코드 경로까지 확정한 결론은 아니다.

감사 코드 작성 중 high far-jump 후주소의 잘못된 고정 기대값을 root가 발견했다.
주소를 추정하지 않고 Python/Capstone이 해석한 far-jump target와 명령 끝주소로
계산하도록 수정했다. 이는 감사 코드 오류 수정이며 CPU 성공이나 음성 대조로 세지 않았다.

## 추가 반례 및 root 재현

후속 독립 검토는 기존 code_check가 초기 ESP와 record 포인터를 고정하지 않으며,
check가 빈 hashes와 임의 command도 허용한다고 지적했다. root가 Python으로
ESP immediate를180100, record 포인터를17ffe0으로 바꾼 각각의 메모리 내
코드와 hashes={}, command=['not-the-recorded-command']를 시험하여 모두 통과함을
직접 확인했다. 현재 실제 파일에서 frame 훼손을 발견한 것은 아니다.

특히 record 포인터17ffe0에서는 handler의[EDI+18]이 saved EFLAGS17fff8과
겹칠 수 있으므로, 해당 전제를 고정하지 않은 감사만으로 frame 비손상을 주장할 수 없다.
주소·변조·범위 계산은 모두 Python으로 수행했다.

보강 계획을 다시 코딩 전 검토받은 뒤 ROM reset/bootstrap, 전체 고정 code image와
padding, labels/lengths, 필수 해시 파일 집합과 command/run metadata를 검사했다.
root가 Capstone의 전체 main/helper/fatal 명령 및16-bit boot 명령을 읽고 기대값을
고정했으며, 감사는 producer를 import하거나 images()를 호출하지 않는다.
ES/GS 로그와 stack/frame/record/result/control 구간의 비중첩도 검사한다.

이는 고정 fixture의 독립 검사 코드와 변경 민감도 보강이다. 기대값 고정 자체는
기대값의 의미가 옳다는 자동 증명도, QEMU 실행 사실의 독립 증명도 아니다.
RF strict 기대값 및 관찰 결과는 변경하지 않았다.

보강 후 검토자는 읽기 전용으로 정상 flags 사례와 기존 반례 거부를 재확인하고,
이번 핵심 누락에 대한 추가 필수 수정을 찾지 못했다고 보고했다. root의 직접 시험과
별도로 기록하며, 이 의견만으로 전체 분석 완료나 RF 계약 성공을 판정하지 않는다.
