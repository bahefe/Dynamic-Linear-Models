import pandas as pd

# Example dataframe
data = {
    'Metric_1': [-10, 20, -5, 30],
    'Metric_2': [15, -25, 10, -10]
}
df = pd.DataFrame(data)

# Create the 'targeted' column
df['targeted'] = df.apply(lambda row: 'targeted' if row['Metric_1'] < 0 and row['Metric_2'] > 0 else '', axis=1)

print(df)