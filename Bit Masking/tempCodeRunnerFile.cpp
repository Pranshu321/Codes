ll ncr(ll n, ll r)
{

  if (r > n)

    return 0;

  ll res = 1;

  if (r > (n - r))

    r = n - r;

  for (int i = 0; i < r; i++)
  {

    res *= (n - i);

    res /= (i + 1);
  }

  return res;
}

int csb(ll n)
{

  int res = 0;

  while (n > 0)
  {

    res += 1;

    n &= (n - 1);
  }

  return res;
}

ll find(ll x, int k, int i)

{

  if (i == 0)

    return 0;

  ll res = 0;

  if ((x & (1LL << i)) == 0)

    res = find(x, k, i - 1);

  else
  {

    ll res1, res2;

    // if we don't pick msb

    res1 = ncr(i, k);

    // we pick msb

    res2 = find(x, k - 1, i - 1);

    res = res1 + res2;
  }

  return res;
}

long long count(long long x)
{

  int k = csb(x); // count set bits

  ll ans = find(x, k, 63);

  return ans;
}