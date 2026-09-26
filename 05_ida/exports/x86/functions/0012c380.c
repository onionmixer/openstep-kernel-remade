/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x12c380. */
_DWORD *__cdecl sub_12C380(_DWORD *a1)
{
  _DWORD *v1; // esi
  int v2; // ecx
  unsigned int v3; // ecx
  _DWORD *result; // eax
  unsigned int v5; // edx
  _DWORD v6[2]; // [esp+8h] [ebp-8h] BYREF

  v1 = (_DWORD *)a1[12]; /*0x12c38b*/
  getthetime(v6); /*0x12c392*/
  v2 = v6[1]; /*0x12c39a*/
  v1[48] = v6[0]; /*0x12c39d*/
  v1[49] = v2; /*0x12c3a3*/
  v3 = (v6[0] - v1[42]) >> 4; /*0x12c3b4*/
  if ( a1[10] == 2 ) /*0x12c3bb*/
  {
    result = *(_DWORD **)(a1[9] + 296); /*0x12c3c0*/
    v5 = result[26]; /*0x12c3c6*/
    if ( v3 >= v5 ) /*0x12c3cb*/
    {
      v5 = result[27]; /*0x12c3cd*/
      goto LABEL_6; /*0x12c3d0*/
    }
LABEL_7:
    v3 = v5; /*0x12c3eb*/
    goto LABEL_8; /*0x12c3eb*/
  }
  result = *(_DWORD **)(a1[9] + 296); /*0x12c3d7*/
  v5 = result[24]; /*0x12c3dd*/
  if ( v3 < v5 ) /*0x12c3e2*/
    goto LABEL_7; /*0x12c3e2*/
  v5 = result[25]; /*0x12c3e4*/
LABEL_6:
  if ( v3 > v5 ) /*0x12c3e9*/
    goto LABEL_7; /*0x12c3e9*/
LABEL_8:
  v1[48] += v3; /*0x12c3ed*/
  return result; /*0x12c3f6*/
}
