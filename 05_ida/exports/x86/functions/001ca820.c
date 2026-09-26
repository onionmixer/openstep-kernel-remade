/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ca820. */
objc_method_description *__cdecl -[Protocol descriptionForClassMethod:](Protocol *self, SEL a2, SEL a3)
{
  objc_method_description *result; // eax

  result = (objc_method_description *)sub_1CA868(self->class_methods, a3); /*0x1ca830*/
  if ( !result ) /*0x1ca83a*/
  {
    if ( self->protocol_list ) /*0x1ca83c*/
      return (objc_method_description *)sub_1CA900(self->protocol_list, a3); /*0x1ca847*/
  }
  return result; /*0x1ca84f*/
}
