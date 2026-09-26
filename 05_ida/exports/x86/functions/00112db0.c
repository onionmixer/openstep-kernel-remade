/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x112db0. */
int __cdecl getc(FILE *a1)
{
  int v1; // edi
  int r; // ebx
  int v3; // edx
  int v4; // eax
  int v5; // edx
  unsigned __int8 *v6; // ecx
  int v7; // eax
  int v8; // eax
  int v10; // [esp+10h] [ebp-4h]

  v10 = spltty(); /*0x112dc1*/
  if ( (int)a1->_p > 0 ) /*0x112dc7*/
  {
    r = a1->_r; /*0x112de8*/
    v1 = *(unsigned __int8 *)r; /*0x112deb*/
    v3 = r; /*0x112dee*/
    LOBYTE(v3) = r & 0xC0; /*0x112df0*/
    v4 = (r & 0x3F) >> 3; /*0x112e03*/
    v5 = *(char *)(v3 + v4 + 4); /*0x112e0a*/
    if ( _bittest(&v5, (r & 0x3F) - 8 * v4) ) /*0x112e17*/
      v1 |= 0x100u; /*0x112e1c*/
    a1->_r = r + 1; /*0x112e23*/
    v6 = a1->_p - 1; /*0x112e28*/
    a1->_p = v6; /*0x112e2b*/
    if ( (int)v6 > 0 ) /*0x112e30*/
    {
      v8 = a1->_r; /*0x112e50*/
      if ( (v8 & 0x3F) != 0 ) /*0x112e55*/
        goto LABEL_11; /*0x112e55*/
      a1->_r = *(_DWORD *)(v8 - 64) + 12; /*0x112e5d*/
      *(_DWORD *)(v8 - 64) = cfreelist; /*0x112e66*/
      v7 = v8 - 64; /*0x112e69*/
    }
    else
    {
      v7 = a1->_r - 1; /*0x112e35*/
      LOBYTE(v7) = v7 & 0xC0; /*0x112e36*/
      a1->_r = 0; /*0x112e38*/
      a1->_w = 0; /*0x112e3f*/
      *(_DWORD *)v7 = cfreelist; /*0x112e4c*/
    }
    cfreelist = v7; /*0x112e6c*/
    cfreecount += 52; /*0x112e71*/
    if ( cwaiting ) /*0x112e7f*/
    {
      wakeup((int)&cwaiting); /*0x112e86*/
      cwaiting = 0; /*0x112e8b*/
    }
  }
  else
  {
    v1 = -1; /*0x112dc9*/
    a1->_p = nullptr; /*0x112dce*/
    a1->_w = 0; /*0x112dd4*/
    a1->_r = 0; /*0x112ddb*/
  }
LABEL_11:
  splx(v10); /*0x112e95*/
  return v1; /*0x112ea3*/
}
