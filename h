import pandas as pd
import numpy as np
from sklearn.linear_model import LinearRegression

# Sample dataframe with two metrics
data = {
    "date": ["2024-01-01", "2024-01-02", "2024-01-03", "2024-01-04", "2024-01-05",
             "2024-01-01", "2024-01-02", "2024-01-03", "2024-01-04", "2024-01-05"],
    "category_1": ["A"] * 5 + ["B"] * 5,
    "category_2": ["X", "X", "Y", "Y", "Y", "X", "X", "Y", "Y", "Y"],
    "metric_1": [1, 2, 3, 4, 5, 5, 4, 3, 2, 1],
    "metric_2": [10, 20, 30, 40, 50, 50, 40, 30, 20, 10],
}

df = pd.DataFrame(data)

# Convert string dates to datetime and then to numeric
df["date"] = pd.to_datetime(df["date"])
df["date_ordinal"] = df["date"].map(lambda x: x.toordinal())

# Function to calculate slope for a specific metric
def calculate_slope(group, metric):
    X = group["date_ordinal"].values.reshape(-1, 1)  # Independent variable
    y = group[metric].values  # Dependent variable
    model = LinearRegression()
    model.fit(X, y)
    return model.coef_[0]  # Slope of the regression line

# Group by categories and calculate slopes for both metrics
result = (
    df.groupby(["category_1", "category_2"])
    .apply(lambda group: pd.Series({
        "slope_metric_1": calculate_slope(group, "metric_1"),
        "slope_metric_2": calculate_slope(group, "metric_2")
    }))
    .reset_index()
)

# Display the result
print(result)