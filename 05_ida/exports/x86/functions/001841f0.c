/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1841f0. */
int __cdecl sgioctl(__int16 a1, int a2, unsigned __int8 *a3)
{
  void *v3; // eax
  void *v4; // esi
  char v6; // al
  id v7; // eax
  char v8; // al
  int v9; // edx
  int v10; // edx
  id v12; // eax
  id v13; // eax
  id v14; // eax
  int v15; // [esp+Ch] [ebp-4h]

  v3 = (void *)sub_18447C(a1); /*0x184201*/
  v4 = v3; /*0x184206*/
  v15 = 0; /*0x184208*/
  if ( !v3 ) /*0x184214*/
    return 6; /*0x18421b*/
  if ( a2 == 536900354 ) /*0x184226*/
  {
    v12 = objc_msgSend(v3, sel_enableAutoSense); /*0x1843a8*/
    goto LABEL_33; /*0x1843a8*/
  }
  if ( a2 > 536900354 ) /*0x18422c*/
  {
    if ( a2 == 1074033415 ) /*0x184282*/
    {
      *(_DWORD *)a3 = objc_msgSend(v3, sel_autoSense) != nullptr; /*0x1843e2*/
      return v15; /*0x1843e4*/
    }
    if ( a2 > 1074033415 ) /*0x184288*/
    {
      if ( a2 == 1074033417 ) /*0x1842ae*/
      {
        v14 = objc_msgSend(v3, sel_controller); /*0x18441f*/
        *(_DWORD *)a3 = objc_msgSend(v14, sel_numberOfTargets); /*0x184430*/
      }
      else if ( a2 < 1074033417 ) /*0x1842b4*/
      {
        v13 = objc_msgSend(v3, sel_controller); /*0x1843fb*/
        *(_DWORD *)a3 = objc_msgSend(v13, sel_maxTransfer); /*0x18440c*/
      }
      else
      {
        if ( a2 != 1074819853 ) /*0x1842c0*/
          return 22; /*0x1842c0*/
        *(_DWORD *)a3 = objc_msgSend(v3, sel_SCSI3_target); /*0x184364*/
        *((_DWORD *)a3 + 1) = v9; /*0x184366*/
        *((_DWORD *)a3 + 2) = objc_msgSend(v4, sel_SCSI3_lun); /*0x184376*/
        *((_DWORD *)a3 + 3) = v10; /*0x184379*/
      }
      return v15; /*0x18437c*/
    }
    if ( a2 != 536900355 ) /*0x184290*/
    {
      if ( a2 == 536900356 ) /*0x18429c*/
      {
        if ( !suser() ) /*0x184434*/
          return *(char *)(dword_1E875C + 104); /*0x184447*/
        if ( objc_msgSend(v4, sel_resetSCSIBus) ) /*0x184454*/
          return 5; /*0x18445d*/
        return v15; /*0x18444a*/
      }
      return 22; /*0x18429c*/
    }
    v12 = objc_msgSend(v3, sel_disableAutoSense); /*0x1843c3*/
LABEL_33:
    if ( v12 ) /*0x1843af*/
      return 22; /*0x1843af*/
    return v15; /*0x1843af*/
  }
  if ( a2 == -2146405620 ) /*0x184234*/
  {
    v8 = suser(); /*0x184318*/
    v7 = objc_msgSend( /*0x18433b*/
           v4,
           sel_setSCSI3Target_lun_isRoot_,
           *(_DWORD *)a3,
           *((_DWORD *)a3 + 1),
           *((_DWORD *)a3 + 2),
           *((_DWORD *)a3 + 3),
           v8);
    goto LABEL_26; /*0x18433b*/
  }
  if ( a2 <= -2146405620 ) /*0x18423a*/
  {
    if ( a2 != -2147323136 ) /*0x184242*/
    {
      if ( a2 == -2147192058 ) /*0x18424e*/
      {
        if ( objc_msgSend(v3, sel_setController_, *(_DWORD *)a3) ) /*0x1842fe*/
          return 19; /*0x18430b*/
        return v15; /*0x184312*/
      }
      return 22; /*0x18424e*/
    }
    v6 = suser(); /*0x1842cc*/
    v7 = objc_msgSend(v4, sel_setTarget_lun_isRoot_, *a3, a3[1], v6); /*0x1842e9*/
LABEL_26:
    if ( v7 ) /*0x184342*/
      return 13; /*0x184348*/
    return v15; /*0x18434f*/
  }
  if ( a2 == -1068207359 ) /*0x184262*/
    return sub_18449C(v3, (int)a3, 0); /*0x18438a*/
  if ( a2 != -1067945202 ) /*0x18426e*/
    return 22; /*0x184468*/
  return sub_18449C(v3, 0, (int)a3); /*0x184475*/
}
