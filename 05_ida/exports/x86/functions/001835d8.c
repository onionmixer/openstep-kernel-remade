/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1835d8. */
int __cdecl sdread(__int16 a1, uio *uio)
{
  id v2; // esi
  size_t v3; // edi
  int v5; // ebx
  id v6; // eax
  id v7; // eax
  id v8; // eax
  int v9; // ebx
  id v10; // [esp+Ch] [ebp-34h]
  int v11; // [esp+10h] [ebp-30h]
  char v12; // [esp+14h] [ebp-2Ch]
  void *v13; // [esp+18h] [ebp-28h]
  id v14; // [esp+20h] [ebp-20h]
  vm_size_t v15; // [esp+30h] [ebp-10h]
  unsigned int v16; // [esp+38h] [ebp-8h]

  v14 = (id)sub_1840EC(a1); /*0x1835f2*/
  v2 = nullptr; /*0x183609*/
  v13 = nullptr; /*0x183612*/
  v12 = 0; /*0x183619*/
  v3 = 0; /*0x18361d*/
  v11 = 0; /*0x18361f*/
  v10 = (id)sub_18414C(a1); /*0x18362c*/
  if ( !v14 ) /*0x183636*/
    return 6; /*0x183638*/
  if ( !(unsigned __int8)objc_msgSend(v14, sel_isFormatted) ) /*0x18364f*/
    return 22; /*0x18365b*/
  v5 = *(_DWORD *)uio; /*0x18366b*/
  v6 = objc_msgSend(v10, sel_controller); /*0x183683*/
  objc_msgSend(v6, sel_getDMAAlignment_); /*0x18368c*/
  if ( forceSdPageAlign ) /*0x18369b*/
    v15 = page_size; /*0x1836a3*/
  if ( v15 > 1 && ((v15 - 1) & *(_DWORD *)v5) != 0 || v16 > 1 && ((v16 - 1) & *(_DWORD *)(v5 + 4)) != 0 ) /*0x1836bf*/
  {
    v12 = 1; /*0x1836c1*/
    v7 = objc_msgSend(v10, sel_controller); /*0x1836e3*/
    v2 = objc_msgSend(v7, sel_allocateBufferOfLength_actualStart_actualLength_); /*0x1836f1*/
    v13 = *(void **)v5; /*0x1836f5*/
    *(_DWORD *)v5 = v2; /*0x1836f8*/
    v3 = *(_DWORD *)(v5 + 4); /*0x1836fa*/
    v11 = *((_DWORD *)uio + 3); /*0x183703*/
    *((_DWORD *)uio + 3) = 1; /*0x183709*/
  }
  v8 = objc_msgSend(v14, sel_blockSize); /*0x18371e*/
  v9 = physio(sdstrategy, dword_1E1268[(unsigned __int8)a1 >> 3], a1, 1, f_minphys, uio, (int)v8); /*0x183749*/
  if ( v12 ) /*0x183752*/
  {
    if ( v11 == 1 ) /*0x183758*/
      bcopy(v2, v13, v3); /*0x183760*/
    else
      copyout(v2, v13, v3); /*0x18376e*/
    IOFree(0, 0); /*0x18377e*/
  }
  return v9; /*0x183788*/
}
