/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x165964. */
task_t task_init()
{
  task_t result; // eax
  boolean_t v1; // [esp-14h] [ebp-14h]
  task_t *v2; // [esp-10h] [ebp-10h]

  task_zone = zinit(140, 71680, 8960, 0, aTasks); /*0x165982*/
  task_create(0, nullptr, (mach_msg_type_number_t)&kernel_task, v1, v2); /*0x165990*/
  result = kernel_task; /*0x165995*/
  *(_DWORD *)(kernel_task + 76) = 1; /*0x16599a*/
  *(_DWORD *)(result + 80) = 1; /*0x1659a1*/
  return result; /*0x1659aa*/
}
