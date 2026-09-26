/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ca0d0. */
unsigned int __cdecl -[Object methodArgSize:](Object *self, SEL a2, SEL name)
{
  objc_method *InstanceMethod; // eax

  InstanceMethod = class_getInstanceMethod(self->isa, name); /*0x1ca0dd*/
  if ( InstanceMethod ) /*0x1ca0e7*/
    return method_getSizeOfArguments(InstanceMethod); /*0x1ca0ea*/
  else
    return 0; /*0x1ca0f4*/
}
