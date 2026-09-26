/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9694. */
id __cdecl -[IONetwork initForNetworkDevice:name:unit:type:maxTransferUnit:flags:](
        IONetwork *self,
        SEL a2,
        id a3,
        const char *a4,
        unsigned int a5,
        const char *a6,
        unsigned int a7,
        unsigned int a8)
{
  objc_super v9; // [esp+Ch] [ebp-8h] BYREF

  v9.receiver = self; /*0x1a96b0*/
  v9.super_class = (Class)stru_1FA244.ext; /*0x1a96b9*/
  -[Object init](&v9, sel_init); /*0x1a96c0*/
  self->_netif = ($8EF4127CF77ECA3DDB612FCF233DC3A8 *)if_attach( /*0x1a96f4*/
                                                        (int)sub_1A95C8,
                                                        0,
                                                        (int)sub_1A95F8,
                                                        (int)sub_1A9630,
                                                        (int)sub_1A965C,
                                                        (int)a4,
                                                        a5,
                                                        (int)a6,
                                                        a7,
                                                        a8,
                                                        0,
                                                        (int)a3);
  return self; /*0x1a96fd*/
}
