/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ac780. */
id __cdecl +[SCSIDisk initialize](id a1, SEL a2)
{
  objc_super v3; // [esp+4h] [ebp-8h] BYREF

  if ( a1 == +[Object class](aScsidisk_0, sel_class) ) /*0x1ac7a2*/
    sd_init_idmap(); /*0x1ac7a4*/
  v3.receiver = a1; /*0x1ac7b0*/
  v3.super_class = (Class)stru_1FAC94.ext; /*0x1ac7b9*/
  return objc_msgSendSuper(&v3, sel_initialize); /*0x1ac7c5*/
}
