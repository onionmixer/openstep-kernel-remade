/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1aadb4. */
void __cdecl -[IOEthernet registerAsDebuggerDevice](IOEthernet *self, SEL a2)
{
  id v2; // eax

  if ( !dword_1E8700 ) /*0x1aadc2*/
  {
    dword_1E8708 = -[Object methodFor:](self, sel_methodFor_, sel_receivePacket_length_timeout_); /*0x1aadd8*/
    v2 = -[Object methodFor:](self, sel_methodFor_, sel_sendPacket_length_); /*0x1aadec*/
    dword_1E870C = (int (__stdcall *)(_DWORD, _DWORD, _DWORD, _DWORD))v2; /*0x1aadf1*/
    if ( dword_1E8708 ) /*0x1aadfd*/
    {
      if ( v2 ) /*0x1aae01*/
        dword_1E8700 = (int)self; /*0x1aae03*/
    }
  }
}
