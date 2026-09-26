/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b47a8. */
void __cdecl -[KeyMap _calcModBit:keyBits:](KeyMap *self, SEL a2, int a3, unsigned int *a4)
{
  char *v4; // ebx
  int v5; // esi
  __int16 *v6; // ebx
  unsigned int v7; // eax
  unsigned int v8; // esi
  _BOOL4 v9; // [esp-4h] [ebp-24h]
  int v10; // [esp+10h] [ebp-10h]
  signed __int16 shorts; // [esp+14h] [ebp-Ch]
  unsigned int v12; // [esp+18h] [ebp-8h]
  int v13; // [esp+1Ch] [ebp-4h]

  v13 = 1 << (a3 + 16); /*0x1b47be*/
  v12 = ~v13 & (unsigned int)objc_msgSend(self->delegate, sel_deviceFlags); /*0x1b47e0*/
  shorts = self->curMapping.shorts; /*0x1b47ed*/
  v4 = self->curMapping.modDefs[a3]; /*0x1b47f7*/
  if ( v4 ) /*0x1b4800*/
  {
    v5 = 0; /*0x1b4802*/
    if ( shorts ) /*0x1b4809*/
    {
      v10 = *(__int16 *)v4; /*0x1b480e*/
      v6 = (__int16 *)(v4 + 2); /*0x1b4811*/
    }
    else
    {
      v10 = (unsigned __int8)*v4; /*0x1b481b*/
      v6 = (__int16 *)(v4 + 1); /*0x1b481e*/
    }
    if ( v10 > 0 ) /*0x1b4822*/
    {
      while ( 1 ) /*0x1b4829*/
      {
        if ( shorts ) /*0x1b4829*/
        {
          v7 = *v6++; /*0x1b482b*/
        }
        else
        {
          v7 = *(unsigned __int8 *)v6; /*0x1b4834*/
          v6 = (__int16 *)((char *)v6 + 1); /*0x1b4837*/
        }
        if ( ((1 << (v7 & 0x1F)) & a4[v7 >> 5]) != 0 ) /*0x1b484f*/
          break; /*0x1b484f*/
        if ( v10 <= ++v5 ) /*0x1b4855*/
          goto LABEL_13; /*0x1b4855*/
      }
      v12 |= v13; /*0x1b485f*/
    }
  }
LABEL_13:
  if ( a3 == 1 ) /*0x1b4866*/
  {
    if ( (v12 & 0x100000) != 0 && !self->curMapping.modDefs[0] && self->curMapping.specialKeys[4] == 0xFFFF ) /*0x1b4890*/
    {
      if ( (v12 & v13) != 0 ) /*0x1b4897*/
      {
        objc_msgSend(self->delegate, sel_setCharKeyActive_, 0); /*0x1b48a1*/
      }
      else if ( !(unsigned __int8)objc_msgSend(self->delegate, sel_charKeyActive) ) /*0x1b48b5*/
      {
        v9 = (unsigned __int8)objc_msgSend(self->delegate, sel_alphaLock) == 0; /*0x1b48e4*/
        objc_msgSend(self->delegate, sel_setAlphaLock_, v9); /*0x1b48f6*/
      }
    }
    v8 = v12 & 0xFFFEFFFF; /*0x1b4901*/
    if ( (unsigned __int8)objc_msgSend(self->delegate, sel_alphaLock) == 1 ) /*0x1b492e*/
      v12 = v8 | 0x10000; /*0x1b4936*/
    else
      v12 = ((v12 & 0x20000) >> 1) | v8; /*0x1b493e*/
  }
  else if ( !a3 ) /*0x1b4948*/
  {
    objc_msgSend(self->delegate, sel_setAlphaLock_, HIWORD(v12) & 1); /*0x1b4965*/
  }
  objc_msgSend(self->delegate, sel_setDeviceFlags_, v12); /*0x1b4982*/
}
