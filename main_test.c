int main (void)
{
	int d_un_test = 42;

	ft_printf("test 1\n");
	ft_printf("%cest 2\n", 't');
	ft_printf("test %d\n", 3);
	ft_printf("%s 4\n", "test");
	ft_printf("%u\n", 4294967295);
	ft_printf("%x\n", 42);
	/*printf("%p\n", &d_un_test);*/
	ft_printf("%p\n", &d_un_test);
}