/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x188044. */
void dma_initialize()
{
  int i; // ebx

  us_spin(1); /*0x18804a*/
  __outbyte(word_1E189C, 0); /*0x18805b*/
  _InterlockedIncrement(dword_1E75EC); /*0x18805c*/
  us_spin(1); /*0x188065*/
  __outbyte(word_1E18AA, 0); /*0x188076*/
  _InterlockedIncrement(dword_1E75EC); /*0x188077*/
  prev_tcstatus0 = 0; /*0x18807e*/
  prev_tcstatus1 = 0; /*0x188088*/
  us_spin(1); /*0x188096*/
  __outbyte(_dma_chip_port, 0x10u); /*0x1880a7*/
  _InterlockedIncrement(dword_1E75EC); /*0x1880a8*/
  us_spin(1); /*0x1880b1*/
  __outbyte(word_1E18A0, 0x10u); /*0x1880c2*/
  _InterlockedIncrement(dword_1E75EC); /*0x1880c3*/
  dma_cmd_regs = 16; /*0x1880ca*/
  byte_1F74E1 = 16; /*0x1880d1*/
  for ( i = 0; i <= 7; ++i ) /*0x1880d8*/
  {
    dma_assign_chan(i); /*0x1880dd*/
    if ( i == 4 ) /*0x1880e8*/
    {
      dma_chan_xfer_mode(4, 3); /*0x188100*/
      dma_unmask_chan(4); /*0x188107*/
    }
    else
    {
      dma_deassign_chan(i); /*0x1880eb*/
      sub_188124(i); /*0x1880f1*/
    }
  }
  dma_buf_initialize(); /*0x188115*/
}
