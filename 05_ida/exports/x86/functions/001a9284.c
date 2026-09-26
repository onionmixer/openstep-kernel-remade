/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a9284. */
int __usercall IOConvertPort@<eax>(int kern_port@<eax>, int a2@<ebx>, int a3, int a4, int a5)
{
  if ( a4 == 1 )
  {
    kern_port = _io_get_kern_port(a3); /*0x1a92a5*/
  }
  else if ( a4 )
  {
    if ( a4 == 2 )
    {
      kern_port = _io_convert_port_in(a3); /*0x1a92b1*/
      if ( !kern_port )
      {
        IOLog((int)"IOConvertPort: Bad Port\n");
        return 0; /*0x1a92c9*/
      }
    }
  }
  else
  {
    kern_port = a3; /*0x1a92a0*/
  }
  if ( a5 == 1 ) /*0x1a92cf*/
    return _io_task_get_port(kern_port); /*0x1a92dd*/
  if ( a5 ) /*0x1a92d1*/
  {
    if ( a5 != 2 ) /*0x1a92d6*/
      return a2; /*0x1a92d6*/
    return _io_convert_port_out(kern_port); /*0x1a92e5*/
  }
  return kern_port; /*0x1a92f1*/
}
