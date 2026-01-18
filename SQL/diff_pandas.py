import pandas as pd

data = [[3, '2020-03-21 10:16:13'], [7, '2020-01-04 13:57:59'],
        [2, '2020-07-29 23:09:44'], [6, '2020-12-09 10:39:37']]
signups = pd.DataFrame(data, columns=['user_id', 'time_stamp']).astype(
    {'user_id': 'Int64', 'time_stamp': 'datetime64[ns]'})
data = [[3, '2021-01-06 03:30:46', 'timeout'], [3, '2021-07-14 14:00:00', 'timeout'], [7, '2021-06-12 11:57:29', 'confirmed'], [7, '2021-06-13 12:58:28',
                                                                                                                                'confirmed'], [7, '2021-06-14 13:59:27', 'confirmed'], [2, '2021-01-22 00:00:00', 'confirmed'], [2, '2021-02-28 23:59:59', 'timeout']]
confirmations = pd.DataFrame(data, columns=['user_id', 'time_stamp', 'action']).astype(
    {'user_id': 'Int64', 'time_stamp': 'datetime64[ns]', 'action': 'object'})

result = pd.merge(signups, confirmations, on='user_id', how='outer', suffixes=('_signup', '_confirm'))
res = result.groupby('user_id').agg(conformation_rate=('action', lambda x: (x == 'confirmed').sum() / x.count()))
res = res.fillna(0)
print(res)