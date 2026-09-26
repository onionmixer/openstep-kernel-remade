/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1c2234. */
IOPCMCIATuple *__cdecl -[IOPCMCIATuple initWithKernTuple:](IOPCMCIATuple *self, SEL a2, id a3)
{
  id *v4; // ebx
  objc_super v5; // [esp+Ch] [ebp-8h] BYREF

  v5.receiver = self; /*0x1c224e*/
  v5.super_class = objc_getOrigClass("Object"); /*0x1c225e*/
  if ( !a3 ) /*0x1c2245*/
    return (IOPCMCIATuple *)-[Object free](&v5, sel_free); /*0x1c2265*/
  -[Object init](&v5, sel_init); /*0x1c228a*/
  v4 = (id *)IOMalloc(0x10u); /*0x1c2296*/
  self->_private = v4; /*0x1c2298*/
  *v4 = a3; /*0x1c229b*/
  *((_BYTE *)v4 + 4) = (unsigned __int8)objc_msgSend(a3, sel_code); /*0x1c22aa*/
  v4[2] = objc_msgSend(a3, sel_length); /*0x1c22ba*/
  v4[3] = nullptr; /*0x1c22bd*/
  return self; /*0x1c22c9*/
}
