# 코딩 전 교차검토와 첫 진단

독립 검토자 vm_contract_review27에게 실제 GC 후 copy 재진입 설계를 검토받았다.
root는 보존된 원본 ASM/C와 확정34 상태를 직접 확인했다. 검토자는 producer/main을
실행하거나 원본·파일을 변경하지 않았다. 계산은 Python으로 수행했다.

채택한 지적:

- DATA 기존 lookup 성공을 검증하고 DATA allocation/zero 분기를 제외한다.
- DATA의 active 제거·busy 설정·재활성화는 예상되는 중간 변화다. payload와
  resident 보존을 metadata 전 과정 불변으로 오해하지 않는다.
- freePT queue는 비어 있으므로 신규 wired PT 경로에서 반환된PG/KE/EXT를
  재사용한다. DATA descriptor attr3와 PDE의 물리주소를 포함한 잔여값을 보존한다.
- recover는 이미 설정되어 있으므로 API로0으로 초기화하지 않는다.
- 같은 바이트를 재복사할 때 최종 동등성만으로 실제 write를 증명할 수 없다.
  root는 src101의245와 이전src100의228이 다름을 Python으로 확인하고, 버퍼는
  변경하지 않은 채 새 caller argument만 지정했다. retry trace/store도 필수다.

첫 진단에서 fresh34 전체 결과는 확정34와 동일했지만 다음 copy의 원본189d1b에서
vector8이 관찰됐다. CPU snapshot·fault after·at_fault CPU는 동일하고, DATA/PT
payload 변화가 없었다. assertion을 삭제하거나 vector14로 다시 표시하지 않았다.

Unicorn2.1.4 공식 소스와 별도 최소 실험의 코딩 전 검토를 새로 요청했다.
원인 후보는 hook 기반 예외 관찰 후 old_exception 상태의 잔류다. 커널에서
실제로 연속한 예외를 처리했다고 볼 수 있는지에 영향을 주므로 이 문제를
구분하지 않은 채 재사용 성공을 주장하지 않는다. 최소 실험의 context 복구는
별도 diagnostic UC에만 적용하며 커널 실행 상태를 교정하는 우회가 아니다.

## 최소 실험의 코딩 전 검토 및 결과 재검토

독립 검토자는 present PDE/code PTE의 Accessed 변화와 NOP의 EIP 변화를
context 복구 동등성 대조에 섞지 말라고 지적했다. root는 present entry의 A를
초기 입력에 명시하고 context 대조를 별도 UC의 첫 fault 직후에 배치했다.
예외 전 context 외에 예외 직후 context 복구 음성 대조도 넣었다.

실측 vector는 같은UC14→8, NOP 사이14→8, fresh14, prefault restore14→14,
postfault restore14→8이었다. 설치된 라이브러리 hash와 열거한24개 공개 필드,
RAM hash를 기록했다. 검토자는 실행/파일수정 없이 JSON과 코드를 읽고 Python으로
RAM을 독립 재구성해 모든 run의 hash 일치를 확인했다.

root/검토자 모두 이를 CPU 전체 또는 native IDT double fault 전달로 확대하지
않는다. opaque context는 내부 여러 값을 포함하므로 하나의 숨은 필드만 바꾼
실험이 아니다. 설치 release 소스와 결과는 old_exception 잔류 가설에 일치하지만
커널 재진입 문제를 해결했다거나 자원 재사용이 완료됐다는 증거는 아니다.

## 직접 pmap_enter 보조 실험 — 계획 검토와 반례

코딩 전 검토에서 vm_page와 pg_desc PV를 구별하고, EAX를 성공 status로 가정하지
않으며, 잠금/zone/NP PDE 잔여값을 수정하지 않는 호출 경계를 채택했다. root는
원본 pmap_enter/expand, zone pop/free, kmem allocation/wiring, map insert/findspace,
object reference/deallocate, rw lock의 ASM을 직접 확인했다.

첫 감사에서 root가 자체 가정 오류를 발견했다. KE 두 번 pop 중 첫 번째는
vm_map_findspace의 174d49→174d4e이고, 재삽입만 17492e→174933이다.
174933 반환 횟수 기대값을 수정했으며 producer/원본/실행 기록은 변경하지 않았다.
이를 음성 대조의 성공 건수로 계산하지 않았다.

추가 읽기 전용 교차검토자가 중간 기록까지 일관되게 변조하는 반례를 제시했다.
root가 deepcopy만 사용해 각각 기존 감사의 수락을 독립 재현했다.

- 16b3c6의 EZ head unlink를 0 대신 KE로 쓰고 다음 free까지 snapshot도 변경.
- 16b3c1의 EZ count를 1 대신 9로 쓰고 다음 DEC까지 snapshot도 변경.
- 173eed의 KO lock 취득을 1 대신 0으로 쓰고 unlock까지 snapshot도 변경.

이후 원본 연산과 명시적 초기 상태를 바탕으로 zone pop/free/pop의 count/head 및
free-element 포인터, sleepable/spin별 잠금/IPL, KO/map/free/global queue 잠금 필드의
**모든 겹치는 쓰기**를 PC/address/width/value 순서로 검사했다. 중요 checkpoint의
allocator/wire 잠금 전제도 추가했다. 위 반례들은 새 회귀시험에서 거부된다.

검토자가 넓은 shared PTE A/D mask의 허용 반례도 지적했다. root의 Python 계산에서
32행 최종 translation의 기록된 쓰기 외 잔여차이는 없었다. 이것만으로 중간값을
추정하지 않고, 모든 checkpoint에서도 byte-exact replay를 적용해 통과를 확인했다.
이 변경은 새 direct 경계에만 적용하며 기존 확정 보고서는 수정하지 않는다.

한정된 민감 상태 전이를 추가한 것이지 일반 GPR/flags/effective-address 계산,
모든 CPU 부작용·concurrency·whole ownership을 검증한 것은 아니다.

보강 후 독립 검토자는 sleepable/spin 및 서로 다른 prefix의 정상 대표 행을 다시
검사했고, 기존 zone unlink/count·KO lock 반례가 민감 전이 검사와 전체 감사에서
거부되며 무관한 shared PTE Dirty 추가도 거부됨을 확인했다. root는 전체32행
감사와 40개 훼손 대조 및 새 산출물5개 해시 동일 재현을 직접 실행했다.
