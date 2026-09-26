/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9a8c. */
$199DFB5D1DF31DC82E78091AC4DEC886 *__cdecl -[IONetbufQueue dequeue](IONetbufQueue *self, SEL a2)
{
  _queueEntry **queueHead; // ecx
  unsigned int queueCount; // eax

  if ( !self->_queueCount ) /*0x1a9a93*/
    return nullptr; /*0x1a9ac8*/
  queueHead = (_queueEntry **)self->_queueHead; /*0x1a9a99*/
  self->_queueHead = *queueHead; /*0x1a9a9e*/
  queueCount = self->_queueCount; /*0x1a9aa1*/
  self->_queueCount = queueCount - 1; /*0x1a9aa7*/
  if ( queueCount == 1 ) /*0x1a9aad*/
  {
    self->_queueTail = nullptr; /*0x1a9aaf*/
    self->_queueHead = nullptr; /*0x1a9ab6*/
  }
  *queueHead = nullptr; /*0x1a9abd*/
  return ($199DFB5D1DF31DC82E78091AC4DEC886 *)queueHead; /*0x1a9acc*/
}
