/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9984. */
IONetbufQueue *__cdecl -[IONetbufQueue initWithMaxCount:](IONetbufQueue *self, SEL a2, unsigned int a3)
{
  objc_super v4; // [esp+8h] [ebp-8h] BYREF

  v4.receiver = self; /*0x1a9999*/
  v4.super_class = (Class)stru_1FA294.super_class; /*0x1a99a2*/
  -[Object init](&v4, sel_init); /*0x1a99a9*/
  self->_queueTail = nullptr; /*0x1a99ae*/
  self->_queueHead = nullptr; /*0x1a99b5*/
  self->_queueCount = 0; /*0x1a99bc*/
  self->_maxCount = a3; /*0x1a99c3*/
  return self; /*0x1a99cb*/
}
