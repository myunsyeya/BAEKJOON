int main()
{
	int A, B, V;
	scanf("%d %d %d", &A, &B, &V);
	V = (V-A)/(A-B) + (((V-A)%(A-B))? 2: 1);
	printf("%d\n", V);
	return 0;
}