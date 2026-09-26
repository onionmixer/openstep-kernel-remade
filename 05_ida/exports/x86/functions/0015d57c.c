/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x15d57c. */
int __cdecl sub_15D57C(int a1, void *a2, _DWORD *a3, _DWORD *a4, _DWORD *a5)
{
  int v6; // eax
  int v7; // [esp+Ch] [ebp-38h]
  int *v8; // [esp+10h] [ebp-34h] BYREF
  _DWORD v9[7]; // [esp+14h] [ebp-30h] BYREF
  _BYTE v10[8]; // [esp+30h] [ebp-14h] BYREF
  int v11; // [esp+38h] [ebp-Ch]
  int v12; // [esp+3Ch] [ebp-8h]

  if ( lookupname(a1, 1, 1, 0, (int)&v8) ) /*0x15d596*/
    return 4; /*0x15d5a7*/
  if ( !check_exec_access(v8) ) /*0x15d5ba*/
  {
    if ( vn_rdwr(0, v8, (int)v9, 28, 0, 1, 1, nullptr) ) /*0x15d5dc*/
      goto LABEL_11; /*0x15d5e6*/
    if ( v9[0] == -17958194 ) /*0x15d5f1*/
    {
      qmemcpy(a2, v9, 0x1Cu); /*0x15d676*/
      *a3 = 0; /*0x15d67b*/
      *a4 = *(_DWORD *)(*v8 + 20); /*0x15d68c*/
    }
    else
    {
      if ( v9[0] != -889275714 && v9[0] != _byteswap_ulong(0xCAFEBABE) ) /*0x15d604*/
        goto LABEL_13; /*0x15d604*/
      v6 = fatfile_getarch(v8, v9, v10); /*0x15d612*/
      if ( v6 ) /*0x15d61c*/
        goto LABEL_17; /*0x15d61c*/
      if ( vn_rdwr(0, v8, (int)v9, 28, v11, 1, 1, nullptr) ) /*0x15d631*/
      {
LABEL_11:
        v6 = 4; /*0x15d63d*/
        goto LABEL_17; /*0x15d642*/
      }
      if ( v9[0] != -17958194 ) /*0x15d64b*/
      {
LABEL_13:
        v6 = 2; /*0x15d64d*/
        goto LABEL_17; /*0x15d652*/
      }
      qmemcpy(a2, v9, 0x1Cu); /*0x15d65a*/
      *a3 = v11; /*0x15d662*/
      *a4 = v12; /*0x15d66a*/
    }
    *a5 = v8; /*0x15d694*/
    return 0; /*0x15d698*/
  }
  v6 = 6; /*0x15d5bc*/
LABEL_17:
  v7 = v6; /*0x15d69c*/
  vn_rele((int)v8); /*0x15d6a3*/
  return v7; /*0x15d6ae*/
}
