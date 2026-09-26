/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x196d14. */
int __cdecl kmopen(__int16 a1, int a2)
{
  int result; // eax
  int v3; // ebx
  _WORD v4[4]; // [esp+8h] [ebp-8h] BYREF

  if ( (_BYTE)a1 ) /*0x196d22*/
    return 6; /*0x196d29*/
  result = (int)objc_msgSend(kmId, sel_kmOpen_, a2); /*0x196d42*/
  if ( !result ) /*0x196d4c*/
  {
    cons._ub._size = 0; /*0x196d57*/
    cons._read = (int (__cdecl *)(void *, char *, int))sub_197134; /*0x196d61*/
    HIBYTE(cons._lb._base) = 2; /*0x196d6b*/
    if ( (cons._ubuf[0] & 4) != 0 ) /*0x196d79*/
    {
      if ( (cons._ubuf[0] & 0x80u) != 0 && *(_WORD *)(*(_DWORD *)(active_u + 28) + 2) ) /*0x196d87*/
        return 16; /*0x196d93*/
    }
    else
    {
      ttychars((int)&cons); /*0x196d9d*/
      cons._ur = 336003288; /*0x196da2*/
      BYTE1(cons._blksize) = 127; /*0x196dac*/
      *(_WORD *)((char *)&cons._lb._size + 1) = 3341; /*0x196dba*/
      *(_DWORD *)cons._ubuf = 16; /*0x196dc1*/
    }
    v3 = (*(&linesw + 12 * SHIBYTE(cons._lb._base)))(a1, &cons); /*0x196de5*/
    if ( !v3 ) /*0x196dec*/
    {
      objc_msgSend(kmId, sel_getScreenSize_, v4); /*0x196e00*/
      unk_1E982C = v4[0]; /*0x196e09*/
      unk_1E982E = v4[1]; /*0x196e11*/
      unk_1E9830 = v4[2]; /*0x196e19*/
      unk_1E9832 = v4[3]; /*0x196e21*/
    }
    return v3; /*0x196e25*/
  }
  return result; /*0x196e2a*/
}
