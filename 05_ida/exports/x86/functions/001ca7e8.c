/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ca7e8. */
objc_method_description *__cdecl -[Protocol descriptionForInstanceMethod:](Protocol *self, SEL a2, SEL a3)
{
  objc_method_description *result; // eax

  result = (objc_method_description *)sub_1CA868(self->instance_methods, a3); /*0x1ca7f8*/
  if ( !result ) /*0x1ca802*/
  {
    if ( self->protocol_list ) /*0x1ca804*/
      return (objc_method_description *)sub_1CA8A0(self->protocol_list, a3); /*0x1ca80f*/
  }
  return result; /*0x1ca817*/
}
