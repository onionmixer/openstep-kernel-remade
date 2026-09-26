
void _zone_init(void)

{
  _zone_map = _kmem_suballoc(_kernel_map,&_zone_min,&_zone_max,_zone_map_size,0);
  return;
}
