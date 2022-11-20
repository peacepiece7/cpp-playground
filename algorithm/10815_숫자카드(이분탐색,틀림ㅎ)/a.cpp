for (int i = 0; i < m; i++) {
		cin >> x;
		int mid = n / 2;
		int lt = 0;
		int rt = n - 1;
		int f = false; 
		while (lt <= rt) {
			mid = (lt + rt) / 2;
			if (v[mid] == x) {
				cout << 1 << " ";
				f = true;
				break;
			}
			else if (v[mid] > x) rt = mid - 1;
			else lt = mid + 1;
		}

}