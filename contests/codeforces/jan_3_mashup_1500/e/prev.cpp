string t;
	V<string> a;
	for (int i = 0; i < sz(s); i++) {
		if (s[i] == '0') {
			int j = i + 1;
			while (j < n && s[i] == s[j]) j++;
			if ((j - i) == 1) t += s[i];
			i = j - 1;
		} else {
			if (i + 1 < sz(s) && s[i + 1] == '1') {
				int j = i + 1;
				while (j < n && s[i] == s[j]) j++;
				i = j - 1;
				t += '1';
				a.push_back(t);
				t = '1';
			} else t += '1';
		}
	}
	if (sz(t)) a.push_back(t);

	auto chk = [&](string& cur) {
		bool f = 0;
		if (sz(cur) == 0) f = 1;
		else if (count(all(cur), '1') == sz(cur)) f = 1;
		else if (count(all(cur), '0') == sz(cur)) f = 1;
		if (f) return f;

		int sp = 0;
		if (cur.front() == '0' or cur.back() == '0') sp = 1;
		int cnt = 0;
		for (int i = 0; i < sz(cur); i++) {
			if (cur[i] == '0' && i + 2 < sz(cur) && cur[i + 1] == '1' && cur[i + 2] == '0') cnt++;
		}
		return ((cnt & 1) || sp);
	};

	bool final = 1;
	for (auto& nt : a) final &= chk(nt);
	if (final) cout << "YES\n";
	else cout << "NO\n";