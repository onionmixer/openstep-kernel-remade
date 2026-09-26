/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x17e4e8. */
int sub_17E4E8()
{
  sub_17E538(); /*0x17e4eb*/
  probeNativeDevices(); /*0x17e4f0*/
  probeHardware(); /*0x17e4f5*/
  probeDirectDevices(); /*0x17e4fa*/
  sub_17E58C(); /*0x17e4ff*/
  objc_msgSend(dword_1E7314, sel_lock); /*0x17e512*/
  objc_msgSend(dword_1E7314, sel_unlockWith_, 1); /*0x17e527*/
  return IOExitThread(); /*0x17e533*/
}
