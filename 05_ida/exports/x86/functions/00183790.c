/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x183790. */
int __cdecl sdwrite(__int16 a1, uio *uio)
{
  void *v2; // esi
  int v4; // ebx
  id v5; // eax
  id v6; // eax
  id v7; // eax
  const void *v8; // edx
  id v9; // eax
  int v10; // ebx
  const void *v11; // [esp+Ch] [ebp-28h]
  id v12; // [esp+10h] [ebp-24h]
  char v13; // [esp+14h] [ebp-20h]
  vm_size_t v14; // [esp+28h] [ebp-Ch]
  unsigned int v15; // [esp+30h] [ebp-4h]

  v2 = (void *)sub_1840EC(a1); /*0x1837a6*/
  v13 = 0; /*0x1837c1*/
  v12 = (id)sub_18414C(a1); /*0x1837cb*/
  if ( !v2 ) /*0x1837d3*/
    return 6; /*0x1837d5*/
  if ( !(unsigned __int8)objc_msgSend(v2, sel_isFormatted) ) /*0x1837e8*/
    return 22; /*0x1837f4*/
  v4 = *(_DWORD *)uio; /*0x183803*/
  v5 = objc_msgSend(v12, sel_controller); /*0x18381b*/
  objc_msgSend(v5, sel_getDMAAlignment_); /*0x183824*/
  if ( forceSdPageAlign ) /*0x183833*/
    v14 = page_size; /*0x18383b*/
  if ( v14 > 1 && ((v14 - 1) & *(_DWORD *)v4) != 0 || v15 > 1 && ((v15 - 1) & *(_DWORD *)(v4 + 4)) != 0 ) /*0x183857*/
  {
    v13 = 1; /*0x183859*/
    v6 = objc_msgSend(v12, sel_controller); /*0x18387b*/
    v7 = objc_msgSend(v6, sel_allocateBufferOfLength_actualStart_actualLength_); /*0x183884*/
    v8 = *(const void **)v4; /*0x183889*/
    v11 = *(const void **)v4; /*0x18388b*/
    *(_DWORD *)v4 = v7; /*0x18388e*/
    if ( *((_DWORD *)uio + 3) == 1 ) /*0x18389a*/
    {
      bcopy(v8, v7, *(_DWORD *)(v4 + 4)); /*0x1838a2*/
    }
    else
    {
      copyin(v11, v7, *(_DWORD *)(v4 + 4)); /*0x1838b5*/
      *((_DWORD *)uio + 3) = 1; /*0x1838bd*/
    }
  }
  v9 = objc_msgSend(v2, sel_blockSize); /*0x1838cf*/
  v10 = physio(sdstrategy, dword_1E1268[(unsigned __int8)a1 >> 3], a1, 0, f_minphys, uio, (int)v9); /*0x1838f9*/
  if ( v13 ) /*0x183902*/
    IOFree(0, 0); /*0x18390c*/
  return v10; /*0x183916*/
}
