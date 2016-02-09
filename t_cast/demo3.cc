int main()
{
	char ch = '9';
	void* pVoid = static_cast<void*> (&ch);
	char* pCh = static_cast<char*> (pVoid);

	return *pCh;
}
