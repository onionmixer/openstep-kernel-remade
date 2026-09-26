/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9a44. */
void __cdecl -[IONetbufQueue enqueue:](IONetbufQueue *self, SEL a2, $199DFB5D1DF31DC82E78091AC4DEC886 *a3)
{
  unsigned int queueCount; // eax

  queueCount = self->_queueCount; /*0x1a9a50*/
  if ( self->_maxCount <= queueCount ) /*0x1a9a56*/
  {
    nb_free((int)a3); /*0x1a9a7d*/
  }
  else
  {
    ++self->_queueCount; /*0x1a9a58*/
    if ( queueCount ) /*0x1a9a5d*/
    {
      *(_DWORD *)self->_queueTail = a3; /*0x1a9a62*/
      self->_queueTail = (_queueEntry *)a3; /*0x1a9a64*/
    }
    else
    {
      self->_queueTail = (_queueEntry *)a3; /*0x1a9a6c*/
      self->_queueHead = (_queueEntry *)a3; /*0x1a9a6f*/
    }
    *(_DWORD *)a3->var0 = 0; /*0x1a9a72*/
  }
}
