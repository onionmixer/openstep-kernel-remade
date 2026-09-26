/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17f61c. */
id __cdecl -[KernBus _insertResource:withKey:](KernBus *self, SEL a2, id a3, const char *a4)
{
  void *resources; // ebx

  resources = self->_resources; /*0x17f62b*/
  if ( (unsigned __int8)objc_msgSend(resources, sel_isKey_, a4) ) /*0x17f637*/
    return nullptr; /*0x17f658*/
  objc_msgSend(resources, sel_insertKey_value_, a4, a3); /*0x17f64d*/
  return a3; /*0x17f65d*/
}
