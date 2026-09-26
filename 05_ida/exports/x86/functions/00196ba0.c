/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x196ba0. */
int __cdecl -[kmDevice relinquishOwnershipRequest:](kmDevice *self, SEL a2, id a3)
{
  $8EF4127CF77ECA3DDB612FCF233DC3A8 *v3; // eax

  v3 = self->fbp[1]; /*0x196ba7*/
  if ( v3 ) /*0x196baf*/
  {
    (*(void (__stdcall **)($8EF4127CF77ECA3DDB612FCF233DC3A8 *))v3)(self->fbp[1]); /*0x196bb4*/
    self->fbp[1] = nullptr; /*0x196bb6*/
  }
  self->fbMode = 4; /*0x196bc0*/
  return 0; /*0x196bcc*/
}
