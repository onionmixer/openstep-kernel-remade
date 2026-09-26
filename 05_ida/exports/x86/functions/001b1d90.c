/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b1d90. */
void __cdecl -[EventDriver _ioOpHandler:](EventDriver *self, SEL a2, void *a3)
{
  _DWORD *v3; // eax
  id v4; // eax
  _DWORD *v5; // edx
  void *v6; // eax

  v3 = *((_DWORD **)a3 + 2); /*0x1b1d97*/
  if ( v3 ) /*0x1b1d9c*/
    *v3 = 0; /*0x1b1d9e*/
  if ( *(_DWORD *)a3 != 1 )
  {
    if ( *(_DWORD *)a3 )
    {
      if ( *(_DWORD *)a3 != 2 )
        IOPanic("EventDriver: Bogus opBuf.op");
    }
    else
    {
      objc_msgSend(*((id *)a3 + 1), sel_unlockWith_, 2); /*0x1b1dc1*/
      IOExitThread(); /*0x1b1dc6*/
    }
    v4 = -[EventDriver _doPerformInIOThread:](self, sel__doPerformInIOThread_, (char *)a3 + 12); /*0x1b1ddd*/
    v5 = *((_DWORD **)a3 + 2); /*0x1b1de5*/
    if ( v5 ) /*0x1b1dea*/
      *v5 = v4; /*0x1b1dec*/
  }
  v6 = *((void **)a3 + 1); /*0x1b1dfd*/
  if ( v6 ) /*0x1b1e02*/
    objc_msgSend(v6, sel_unlockWith_, 2); /*0x1b1e0e*/
}
