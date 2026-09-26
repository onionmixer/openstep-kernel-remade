/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1b1bfc. */
int __cdecl -[EventDriver _doPerformInIOThread:](EventDriver *self, SEL a2, void *a3)
{
  const char *v4; // eax
  const char *ClassName; // [esp-Ch] [ebp-14h]
  const char *Name; // [esp-8h] [ebp-10h]

  if ( (unsigned __int8)objc_msgSend(*(id *)a3, sel_respondsTo_, *((_DWORD *)a3 + 1)) )
  {
    objc_msgSend(*(id *)a3, sel_perform_with_, *((_DWORD *)a3 + 1), *((_DWORD *)a3 + 2)); /*0x1b1c32*/
    return 0; /*0x1b1c37*/
  }
  else
  {
    Name = sel_getName(*((SEL *)a3 + 1)); /*0x1b1c45*/
    ClassName = object_getClassName(*(id *)a3); /*0x1b1c51*/
    v4 = -[IODevice name](self, sel_name); /*0x1b1c5d*/
    IOLog((int)"%s: _doPerformInIOThread: [%s] does not respond to SEL [%s]\n", v4, ClassName, Name);
    return -703; /*0x1b1c70*/
  }
}
