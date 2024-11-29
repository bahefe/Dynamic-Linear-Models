import plotly.graph_objects as go
from plotly.subplots import make_subplots

# Sample data
x = [1, 2, 3, 4, 5]
y1 = [10, 20, 30, 40, 50]  # Data for primary y-axis
y2 = [5, 15, 25, 35, 45]   # Data for secondary y-axis

# Create a subplot with secondary y-axis
fig = make_subplots(specs=[[{"secondary_y": True}]])

# Add first trace (primary y-axis)
fig.add_trace(
    go.Scatter(x=x, y=y1, mode='lines+markers', name="Primary Y"),
    secondary_y=False
)

# Add second trace (secondary y-axis)
fig.add_trace(
    go.Scatter(x=x, y=y2, mode='lines+markers', name="Secondary Y"),
    secondary_y=True
)

# Update layout
fig.update_layout(
    title="Scatter Plot with Two Y Axes",
    xaxis_title="X Axis",
    yaxis_title="Primary Y Axis",
    yaxis2_title="Secondary Y Axis"
)

# Show the plot
fig.show()