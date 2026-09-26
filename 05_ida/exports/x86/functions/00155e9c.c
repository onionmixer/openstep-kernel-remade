/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x155e9c. */
int __cdecl port_type(int a1, int a2, int *a3)
{
  int v3; // eax
  int v4; // edx
  int *v6; // eax
  int v7; // edi
  _BYTE v8[4]; // [esp+Ch] [ebp-Ch] BYREF
  int v9; // [esp+10h] [ebp-8h] BYREF
  int v10; // [esp+14h] [ebp-4h] BYREF

  if ( !a1 ) /*0x155ead*/
    return 4; /*0x155ead*/
  v3 = ipc_right_lookup_write(a1, a2, &v9); /*0x155eb8*/
  if ( !v3 ) /*0x155ec4*/
  {
    v4 = ipc_right_info(a1, a2, v9, &v10, v8); /*0x155ed9*/
    if ( !v4 ) /*0x155ee0*/
      _InterlockedExchange((volatile __int32 *)(a1 + 8), 0); /*0x155ee4*/
    v3 = v4; /*0x155ee7*/
  }
  if ( v3 ) /*0x155eeb*/
    return 4; /*0x155ef2*/
  v6 = (int *)(v10 & 0x1F0000); /*0x155ef7*/
  if ( (v10 & 0x1F0000) == 0x30000 ) /*0x155f01*/
  {
LABEL_19:
    v7 = 7; /*0x155f3c*/
    goto LABEL_22; /*0x155f41*/
  }
  if ( (v10 & 0x1F0000u) > 0x30000 ) /*0x155f03*/
  {
    if ( v6 == (int *)0x80000 ) /*0x155f1d*/
    {
      v7 = 9; /*0x155f44*/
      goto LABEL_22; /*0x155f49*/
    }
    if ( (unsigned int)v6 > 0x80000 ) /*0x155f1f*/
    {
      if ( v6 != &dword_100000 ) /*0x155f31*/
        goto LABEL_21; /*0x155f31*/
    }
    else if ( v6 != (int *)0x40000 ) /*0x155f26*/
    {
LABEL_21:
      panic(aConvertPortTyp); /*0x155f4c*/
    }
  }
  else if ( v6 != (int *)0x10000 ) /*0x155f0a*/
  {
    if ( v6 != (int *)0x20000 ) /*0x155f11*/
      goto LABEL_21; /*0x155f11*/
    goto LABEL_19; /*0x155f11*/
  }
  v7 = 1; /*0x155f33*/
LABEL_22:
  *a3 = v7; /*0x155f56*/
  return 0; /*0x155f60*/
}
