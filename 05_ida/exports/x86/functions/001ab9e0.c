/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ab9e0. */
int __cdecl -[IOTokenRing performCommand:data:](IOTokenRing *self, SEL a2, const char *a3, void *a4)
{
  int v4; // ebx

  v4 = 0; /*0x1ab9e8*/
  if ( !strcmp(a3, "setflags") ) /*0x1ab9f0*/
    return 0; /*0x1ab9fc*/
  if ( strcmp(a3, "getaddr") ) /*0x1aba06*/
    return 22; /*0x1aba28*/
  bcopy(&self->_nodeAddress, a4, 6u); /*0x1aba21*/
  return v4; /*0x1aba32*/
}
