/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x134f94. */
opaque_auth *authkern_create()
{
  opaque_auth *v0; // ebx

  v0 = (opaque_auth *)kalloc(0x28u); /*0x134f9f*/
  bzero(v0, 0x28u); /*0x134fa4*/
  v0[2].oa_length = (unsigned int)&unk_1DCD88; /*0x134fa9*/
  v0->oa_flavor = 1; /*0x134fb0*/
  v0[1] = _null_auth; /*0x134fbc*/
  return v0; /*0x134fd3*/
}
