/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x195a50. */
// bad sp value at call has been detected, the output may be wrong!
void __cdecl -[kmDevice dispatchKeyboardEvent:](kmDevice *self, SEL a2, $88DEA2CADEC1641AD84155FE76C340B7 *a3)
{
  int v3; // edx
  unsigned int var1; // eax
  int v5; // ebx
  int v6; // edx
  unsigned int v7; // eax
  int v8; // edx
  int v9; // ebx
  int v10; // ebx
  $06E236A3989EA52BCBC585244E9C0693 *p_inBufLock; // edx
  int inDex; // edx
  int v13; // eax
  int v14; // eax

  v3 = 0; /*0x195a5c*/
  var1 = a3->var1; /*0x195a5e*/
  if ( var1 == 54 ) /*0x195a64*/
  {
    dword_1E7758 = a3->var2; /*0x195ad4*/
    a3->var1 = 0; /*0x195ada*/
  }
  else if ( var1 > 0x36 ) /*0x195a66*/
  {
    if ( var1 == 96 ) /*0x195a7b*/
    {
      dword_1E7750 = a3->var2; /*0x195aac*/
      a3->var1 = 0; /*0x195ab2*/
    }
    else if ( var1 > 0x60 ) /*0x195a7d*/
    {
      if ( var1 != 97 ) /*0x195a8f*/
        goto LABEL_18; /*0x195a8f*/
      dword_1E7760 = a3->var2; /*0x195afc*/
      a3->var1 = 0; /*0x195b02*/
    }
    else
    {
      if ( var1 != 56 ) /*0x195a82*/
        goto LABEL_18; /*0x195a82*/
      dword_1E775C = a3->var2; /*0x195ae8*/
      a3->var1 = 0; /*0x195aee*/
    }
  }
  else if ( var1 == 29 ) /*0x195a6b*/
  {
    dword_1E774C = a3->var2; /*0x195a98*/
    a3->var1 = 0; /*0x195a9e*/
  }
  else
  {
    if ( var1 != 42 ) /*0x195a70*/
    {
LABEL_18:
      v3 = 1; /*0x195b0c*/
      goto LABEL_19; /*0x195b0c*/
    }
    dword_1E7754 = a3->var2; /*0x195ac0*/
    a3->var1 = 0; /*0x195ac6*/
  }
LABEL_19:
  if ( !v3 ) /*0x195b13*/
    goto LABEL_34; /*0x195b13*/
  v5 = 0; /*0x195b19*/
  if ( dword_1E7758 || dword_1E7754 ) /*0x195b2b*/
    v5 = 1; /*0x195b2d*/
  v6 = dword_1E774C || dword_1E7750 ? 220 : 0;
  v7 = v6 + (v5 | (2 * a3->var1)); /*0x195b57*/
  v8 = (unsigned __int16)ascii[v7]; /*0x195b59*/
  if ( dword_1E7760 || dword_1E775C ) /*0x195b71*/
    v9 = 128; /*0x195b73*/
  else
    v9 = 0; /*0x195b7c*/
  switch ( ascii[v7] ) /*0x195b89*/
  {
    case 257: /*0x195b89*/
    case 258: /*0x195b89*/
    case 260: /*0x195b89*/
    case 262: /*0x195b89*/
    case 263: /*0x195b89*/
    case 264: /*0x195b89*/
      break;
    default:
      v8 |= v9; /*0x195bb0*/
      break; /*0x195bb0*/
  }
  v10 = v8; /*0x195bb2*/
  if ( !a3->var2 ) /*0x195bb4*/
LABEL_34:
    v10 = 256; /*0x195bba*/
  if ( v10 != 256 ) /*0x195bc5*/
  {
    if ( (*((_BYTE *)self + 292) & 1) != 0 ) /*0x195bd2*/
    {
      p_inBufLock = &self->inBufLock; /*0x195bd4*/
      do /*0x195bee*/
      {
        while ( p_inBufLock->locked ) /*0x195bdc*/
          ; /*0x195bde*/
      }
      while ( _InterlockedExchange((volatile __int32 *)p_inBufLock, 1) == 1 ); /*0x195bee*/
      inDex = self->inDex; /*0x195bf0*/
      v13 = inDex + 1; /*0x195bf6*/
      if ( inDex == 15 ) /*0x195bfc*/
        v13 = 0; /*0x195bfe*/
      if ( self->outDex != v13 ) /*0x195c06*/
      {
        self->inBuf[inDex] = v10; /*0x195c08*/
        v14 = self->inDex + 1; /*0x195c15*/
        if ( self->inDex == 15 ) /*0x195c19*/
          v14 = 0; /*0x195c1b*/
        self->inDex = v14; /*0x195c1d*/
        thread_wakeup_prim((int)self->inBuf, 0, 0); /*0x195c2e*/
      }
      _InterlockedExchange((volatile __int32 *)&self->inBufLock, 0); /*0x195c35*/
    }
    else
    {
      (*(&off_1DAFFC + 12 * SHIBYTE(cons._lb._base)))(v10, &cons); /*0x195c59*/
    }
  }
}
